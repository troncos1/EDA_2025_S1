# EDA_2025_S1
develop and teting of tests and challenges of the course data structures and algorythms (EDA) 
# Git Commands Cheatsheet

## Setup and Configuration
```
# Initialize a repository
git init

# Clone a repository
git clone https://github.com/username/repository.git

# Clone a specific branch
git clone -b branch-name https://github.com/username/repository.git

# Configure user info
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"

# Configure editor
git config --global core.editor "code --wait"

# List configurations
git config --list
```

## Basic Commands
```
# Check status
git status

# Add files to staging
git add filename.txt
git add .                 # Add all changes

# Commit changes
git commit -m "Commit message"

# Commit with both add and commit for tracked files
git commit -am "Commit message"

# View history
git log
git log --oneline         # Compact view
git log --graph --oneline # Graph view

# Show changes
git diff                  # Working directory vs staging
git diff --staged         # Staging vs last commit
```

## Branching
```
# List branches
git branch                # Local branches
git branch -r             # Remote branches
git branch -a             # All branches

# Create a branch
git branch branch-name

# Switch to a branch
git checkout branch-name

# Create and switch to a branch
git checkout -b branch-name

# Delete a branch
git branch -d branch-name
git branch -D branch-name  # Force delete

# Rename current branch
git branch -m new-name
```

## Remote Operations
```
# List remotes
git remote -v

# Add a remote
git remote add origin https://github.com/username/repository.git

# Fetch from remote
git fetch origin

# Pull from remote (fetch + merge)
git pull origin branch-name

# Push to remote
git push origin branch-name

# Push a new branch to remote
git push -u origin branch-name

# Delete a remote branch
git push origin --delete branch-name
```

## Merging and Rebasing
```
# Merge a branch into current branch
git merge branch-name

# Merge with commit message
git merge branch-name -m "Merge message"

# Merge with no fast-forward
git merge --no-ff branch-name

# Abort a merge
git merge --abort

# Rebase current branch onto another
git rebase branch-name

# Interactive rebase
git rebase -i HEAD~3      # Rebase last 3 commits
```

## Stashing
```
# Stash changes
git stash

# Stash with message
git stash save "Work in progress"

# List stashes
git stash list

# Apply stash (keep in stash list)
git stash apply

# Apply specific stash
git stash apply stash@{2}

# Apply and remove stash
git stash pop

# Drop a stash
git stash drop stash@{0}

# Clear all stashes
git stash clear
```

## Undoing Changes
```
# Restore file from staging area
git restore --staged filename.txt

# Restore file to last commit version
git restore filename.txt

# Revert a commit (creates new commit)
git revert commit-hash

# Reset to a commit (moves HEAD)
git reset --soft commit-hash   # Keep changes staged
git reset commit-hash          # Keep changes unstaged
git reset --hard commit-hash   # Discard all changes

# Amend last commit
git commit --amend -m "New message"

# Amend last commit without changing message
git commit --amend --no-edit
```

## Tags
```
# List tags
git tag

# Create a tag
git tag v1.0.0

# Create an annotated tag
git tag -a v1.0.0 -m "Version 1.0.0"

# Push tags to remote
git push origin v1.0.0
git push origin --tags      # Push all tags

# Delete a tag
git tag -d v1.0.0

# Delete a remote tag
git push origin --delete v1.0.0
```

## Advanced Operations
```
# Check file history
git blame filename.txt

# Search through commits
git grep "search term"

# Cherry-pick a commit
git cherry-pick commit-hash

# Squash multiple commits
git rebase -i HEAD~3      # Then mark commits as "squash"

# Find which commit changed a line
git log -S "search string" --patch

# Create a patch
git format-patch master --stdout > patch.diff

# Apply a patch
git apply patch.diff

# Add a submodule
git submodule add https://github.com/username/repo.git path/to/submodule

# Update submodules
git submodule update --init --recursive
```

## Common Workflows
```
# Create a feature branch
git checkout -b feature/name

# Work and commit changes
git add .
git commit -m "Add feature"

# Keep branch updated with main
git fetch origin
git rebase origin/main

# Push feature branch
git push -u origin feature/name

# Create pull request (via GitHub/GitLab)

# After PR is merged, clean up
git checkout main
git pull origin main
git branch -d feature/name
```

## Collaboration Tips
```
# Show all branches and their tracking info
git branch -vv

# Set upstream tracking
git branch --set-upstream-to=origin/branch-name branch-name

# See history of changes to HEAD
git reflog

# See who changed a line
git blame filename.txt

# Create a gitignore file
echo "node_modules/" > .gitignore
```

