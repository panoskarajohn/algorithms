#include "my_calendar_one.h"

#include <gtest/gtest.h>

TEST(MyCalendarOne, All) {
    // ─── Basic booking ────────────────────────────────────────────────────────
    {
        MyCalendarOne cal;
        EXPECT_TRUE(cal.book(10, 20));
        EXPECT_FALSE(cal.book(15, 25));  // overlaps [10, 20)
        EXPECT_TRUE(cal.book(20, 30));   // adjacent, no overlap
    }

    // ─── Non-overlapping / adjacent events ───────────────────────────────────
    {
        MyCalendarOne cal;
        EXPECT_TRUE(cal.book(0, 10));
        EXPECT_TRUE(cal.book(10, 20));  // adjacent end-to-start is allowed
        EXPECT_TRUE(cal.book(20, 30));
        EXPECT_TRUE(cal.book(30, 40));
    }

    // ─── Fully contained overlap ──────────────────────────────────────────────
    {
        MyCalendarOne cal;
        EXPECT_TRUE(cal.book(0, 100));
        EXPECT_FALSE(cal.book(10, 20));  // fully inside [0, 100)
        EXPECT_FALSE(cal.book(0, 100));  // exact duplicate
    }

    // ─── Partial overlaps ─────────────────────────────────────────────────────
    {
        MyCalendarOne cal;
        EXPECT_TRUE(cal.book(10, 20));
        EXPECT_FALSE(cal.book(5, 15));   // overlaps from the left
        EXPECT_FALSE(cal.book(15, 25));  // overlaps from the right
    }

    // ─── Single-unit events ───────────────────────────────────────────────────
    {
        MyCalendarOne cal;
        EXPECT_TRUE(cal.book(5, 6));
        EXPECT_TRUE(cal.book(6, 7));   // adjacent, fine
        EXPECT_FALSE(cal.book(5, 6));  // exact duplicate
    }

    // ─── Independent instances share no state ────────────────────────────────
    {
        MyCalendarOne cal1;
        MyCalendarOne cal2;
        EXPECT_TRUE(cal1.book(10, 20));
        EXPECT_TRUE(cal2.book(10, 20));
        EXPECT_FALSE(cal1.book(15, 25));
        EXPECT_FALSE(cal2.book(15, 25));
        EXPECT_TRUE(cal1.book(20, 30));
        EXPECT_TRUE(cal2.book(20, 30));
    }
}
