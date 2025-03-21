

# GIT Merge Problems


## Inspect
### Inspect it with git status
git fetch  # Just download changes without merging
git log --oneline --graph --decorate --all  # See all branches
git diff main origin/main  # See differences

### VS CODE
#click on Fecth to fecth changes without merging

### GIT LENS EXTENSION
#click on Source Control Graph

## Merge Options
Solutions
Option 1: Merge (creates a merge commit)
This creates a new "merge commit" that combines both histories. Your commit history will show a branch and merge pattern.
Best for: When you want to preserve the exact history and chronology of all commits.
```
git config pull.rebase false
git pull
```

Option 2: Rebase (replays your commits on top of remote)
This takes your local commits, temporarily removes them, pulls the remote changes, and then replays your commits on top. Creates a linear history.
Best for: Keeping a clean, linear history without merge commits.
```
git config pull.rebase true
git pull
```


Option 3: Fast-forward only (safest)
This will only pull if your branch can be fast-forwarded (no divergence). Since you already have divergence, this will fail until you manually resolve the situation.
Best for: Preventing accidental merges.
```
git config pull.ff only
git pull
```


Setting a Global Default
If you have a preference for how to handle this situation every time, you can set a global config:
```
git config --global pull.rebase false  # Always merge
# OR
git config --global pull.rebase true   # Always rebase
```


## Solve Conflicts

### Using VS Code to Resolve Conflicts

### Command Line Approach
```
# Edit the file with your preferred editor
nano mylibx/Makefile

# After manually resolving conflicts, stage the file
git add mylibx/Makefile

# Complete the merge
git commit -m "Merge branch 'main' and resolve conflicts"
```
