#pragma once

#include <chrono>
#include <functional>
#include <future>
#include <memory>
#include <thread>
#include <tuple>

template <typename Func> auto runWithTimeout(int timeoutMs, Func &&func) {
    using ReturnType = decltype(func());

    auto promise = std::make_shared<std::promise<ReturnType>>();
    auto future = promise->get_future();

    std::thread worker([promise, func = std::forward<Func>(func)]() mutable {
        try {
            if constexpr (std::is_void_v<ReturnType>) {
                func();
                promise->set_value();
            } else {
                promise->set_value(func());
            }
        } catch (...) {
            try {
                promise->set_exception(std::current_exception());
            } catch (...) {
            }
        }
    });

    worker.detach(); // Detach immediately - let it run in background

    auto status = future.wait_for(std::chrono::milliseconds(timeoutMs));

    if (status == std::future_status::timeout) {
        throw std::runtime_error("Function timed out - possible infinite loop");
    }

    return future.get();
}
