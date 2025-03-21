
export default function Login() {
  return (
  <form action="/login" method="post" class="login-form">
  <input
    type="text"
    name="handle"
    placeholder="Enter your handle (eg alice.bsky.social)"
    required
  />
  <button type="submit">Log in</button>
</form>

  );
}