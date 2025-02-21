# Setting Up SSH Connection with GitHub

This guide walks you through setting up an SSH key to authenticate with GitHub, ensuring secure and password-free access.

## 1. Check for Existing SSH Keys

Before generating a new key, check if you already have one:

```bash
ls -al ~/.ssh
```

If you see files like `id_rsa.pub` or `id_ed25519.pub`, you might already have a key.

## 2. Generate a New SSH Key

If no key exists, generate a new one:

```bash
ssh-keygen -t ed25519 -C "your_email@example.com"
```

- Save the key in `~/.ssh/` when prompted.

- Optionally, set a passphrase for extra security.

## 3. Add the SSH Key to GitHub

Copy the public key to the clipboard:

```bash
cat ~/.ssh/id_ed25519.pub | pbcopy  # macOScat
cat ~/.ssh/id_ed25519.pub | xclip -selection clipboard  # Linux
```

Then:

1. Go to [GitHub SSH settings](https://github.com/settings/keys).

2. Click **New SSH Key**.

3. Paste the key and save. 

## 4. Test the Connection

Verify the connection:

```bash
ssh -T git@github.com
```

If successful, you’ll see:

```bash
Hi username! You've successfully authenticated, but GitHub does not provide shell access.
```
