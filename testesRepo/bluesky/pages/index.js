import styles from './styles.module.css';
import { useState } from "react";

export default function Login() {

  const [error, setError] = useState(null);

  const [username, setUsername] = useState("");
  const [password, setPassword] = useState("");

  async function handleSubmit(event) {
    try {
      const response = await fetch("/api/v1/login", {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({ username, password }),
      });

      if (!response.ok) {
        const error = await response.json();
        throw new Error(error.message);
      }

      const data = await response.json();
      console.log(data);
      alert("logado com sucesso");
    } catch (error) {
      setError(error.message);
    }
  }

  return (
    <div id="root">
    <div id="header">
      <h1>Statusphere</h1>
      <p>Set your status on the Atmosphere.</p>
    </div>
    <div className={styles.container}>
      <form action={handleSubmit} method="post" className={styles.login_form}>
        <input
          type="text"
          name={username}
          onChange={(e) => setUsername(e.target.value)}
          placeholder="Enter your handle (eg alice.bsky.social)"
          required
        />
        <input
          type="password"
          name={password}
          onChange={(e) => setPassword(e.target.value)}
          required
        />
        <button type="submit">Log in</button>
        {error && (<><p>Error: <i>${error}</i></p></>)}
      </form>
      <div className={styles.signup_cta}>
        Don't have an account on the Atmosphere?
        <a href="https://bsky.app">Sign up for Bluesky</a> to create one now!
      </div>
    </div>
  </div>
  );
}