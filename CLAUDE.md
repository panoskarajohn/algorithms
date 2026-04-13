# Project conventions for Claude

## Tests
- All tests for a problem live in a **single** `TEST(SuiteName, All)` macro.
- Each scenario gets its own anonymous `{}` block with a `// ─── section ───` comment above it.
- Never create multiple `TEST()` macros per file unless explicitly asked.
