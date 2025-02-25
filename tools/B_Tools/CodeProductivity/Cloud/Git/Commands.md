``` sh
# Create and switch to the "new-feature" branch
git checkout -b new-feature 

# Make some changes to your files... (e.g., edit index.html and style.css)

# Stage the changes
git add index.html style.css

# Commit the changes with a message
git commit -m "Add initial implementation of new feature"

# Switch to the "main" branch
git checkout main

# Pull the latest changes from the remote "main" branch 
# (this fetches and merges)
git pull origin main 

# Uh oh, a merge conflict! Let's resolve it...
# Open the conflicting file(s) in your editor (e.g., index.html)
# Manually edit the file to choose the correct changes or combine them
# Save the file

# Stage the resolved file(s)
git add index.html 

# Continue the merge by committing the resolution
git commit -m "Resolve merge conflict in index.html"

# Now, merge the "new-feature" branch into "main"
git merge new-feature

# Another merge conflict!  (This time, let's say it's in style.css)
# Open style.css in your editor, resolve the conflict, and save the file

# Stage the resolved file
git add style.css

# Commit the merge resolution
git commit -m "Resolve merge conflict in style.css"

# Push the updated "main" branch to the remote repository
git push origin main

```

### Merge 
```
git config pull.rebase false
```
	creates a branch and merge it
## Rebase
````
git config pull.rebase true
````
	just overwrites into local from host
## Fast-forward only**
```
git config pull.ff only
```
	only pull if no conflict exists