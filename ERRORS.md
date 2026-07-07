# Errors

Tracks problems that are blocked on something outside our solution (LeetCode
platform/judge issues, CLI bugs, etc.) rather than on our code being wrong.
Each entry links to a detailed writeup in `errors/`.

| Problem | Symptom | Status | Details |
|---|---|---|---|
| [602. Friend Requests II: Who Has the Most Friends](https://leetcode.com/problems/friend-requests-ii-who-has-the-most-friends/) | `submit` rejected with 401/403 ("session expired or invalid") while `test` passes and `submit` works fine on other problems in the same session | Open — likely a problem-specific judge issue on LeetCode's side, not a session/CLI bug | [errors/602.friend-requests-ii-who-has-the-most-friends.md](errors/602.friend-requests-ii-who-has-the-most-friends.md) |
