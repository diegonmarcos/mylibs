# Python setup
- **Create a virtual environment:**
    ```
    python3.12 -m venv .venv 
    ```
    (This creates a virtual environment in a named `.venv` in your current directory. You can choose a different name and .)
    
- **Activate the environment:**
    
    Bash
    ```
    source .venv/bin/activate
    ```
    
- **Install `ipykernel` within the environment:**
    ```
    pip install ipykernel
    ```
    
    Use code [with caution.](/faq#coding)
    
- **(Optional) Make the kernel available to Jupyter:**
    
    Bash
    
    ```
    python -m ipykernel install --user --name=.venv 
    ```
    
    Use code [with caution.](/faq#coding)
    
    (Replace `.venv` with your environment's name if you chose a different one.)

# Jupyter start

Create a file wit this extension
```
*.ipynb
```
