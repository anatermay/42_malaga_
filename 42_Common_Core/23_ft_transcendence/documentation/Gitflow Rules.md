## Branching Architecture

In Gitflow, we organize work by **intent**. We separate the "Stable World" (Production) from the "Development World" (In-progress).

|Branch|Icon|Role|Source|Destination|
|:--|:--|:--|:--|:--|
|**`main`**|🚀|**Production**: Stable, tested code only.|-|-|
|**`develop`**|🛠️|**Integration**: The main workspace for the next version.|`main`|`main`|
|**`feature/`**|✨|**Features**: Isolated development for specific tasks.|`develop`|`develop`|
|**`bugfix/`**|🐛|**Dev Fix**: Fixing bugs found during development.|`develop`|`develop`|
|**`hotfix/`**|🚑|**Prod Fix**: Critical repairs for bugs found on `main`.|`main`|`main` & `develop`|
## ✍️ 2. The "Atomic Commit"
### Professional Commit Structure (Conventional Commits)

```
type(scope): short summary in present tense

[Optional: why was this change made? What is the impact?]
```

### Choosing the Right "Type"
- **`feat`**: A new feature (e.g., `feat: add multiplication logic`).
- **`fix`**: A bug fix.
    - _Note:_ You usually perform a `fix` inside a `bugfix/` or `hotfix/` branch.
- **`refactor`**: Code changes that neither fix a bug nor add a feature (cleaning up).
- **`style`**: Changes that do not affect the meaning of the code (white-space, formatting).
- **`docs`**: Documentation changes only.

## 🛠️ 3. Survival Commands & Syntax

### Isolate your Task (Feature)

Work peacefully without disturbing the main codebase:

```shell
git checkout -b feature/task-name develop
```

### The "Historical" Merge (`--no-ff`)

This is the golden rule of Gitflow. When merging a feature back to `develop`:

```shell
git checkout develop
git pull origin develop   # Always update before merging!
git merge --no-ff feature/task-name
git push origin develop   # Share the integration
```

**Why `--no-ff`?**

- By default, Git performs a "Fast-Forward" (merging the history into a flat line).
- `--no-ff` forces a **Merge Commit**. This visually preserves the branch in your graph, showing exactly when a feature was worked on and by whom.

### Managing Emergencies (Hotfix)

If production (`main`) crashes, don't wait for the next release:

1. Create `hotfix/bug-name` from `main`.
2. Fix it, then merge into `main` (with a **Tag** like `v1.0.1`).
3. **Crucial:** Merge it back into `develop` so the bug never returns!


*This is taken from the  [Gitflow_Master](https://github.com/Maj-e/Gitflow_Master)repository by [Maj-e](https://github.com/Maj-e/)  *