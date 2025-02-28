/* // In your extension's package.json:

{
    "contributes": {
        "commands": [
            {
                "command": "my-pushswap-extension.startDebug",
                "title": "Start PushSwap Debugging"
            }
        ],
		"activationEvents": [
            "onUri",  // Activate when a URI is opened
			"onCommand:my-pushswap-extension.startDebug" // Activate when the command is run
        ],
        "uriOpeners": [
            {
                "scheme": "vscode",
                "authority": "my-pushswap-extension", // Your extension's ID
                "path": "/startDebug" // The path to handle
            }
        ]
    }
} */

/* 
code --open-url "vscode://my-pushswap-extension/startDebug?configName=PUSHSWAP_DBG"
 */

// In your extension's activate function:

export function activate(context: vscode.ExtensionContext) {

    // Register the URI handler
    context.subscriptions.push(vscode.window.registerUriHandler({
        handleUri(uri: vscode.Uri): vscode.ProviderResult<void> {
            if (uri.path === '/startDebug' && uri.query.startsWith('configName=')) {
                const configName = uri.query.substring('configName='.length);
                startDebugging(configName); // Call a function to start debugging
            } else {
                vscode.window.showErrorMessage('Invalid URI for debugging.');
            }
            return;
        }
    }));

   //Register a simple command, if you prefer trigger the command by keybinding, for example.
    context.subscriptions.push(
        vscode.commands.registerCommand('my-pushswap-extension.startDebug', () => {
            startDebugging("PUSHSWAP_DBG");
        })
    );
}

async function startDebugging(configName: string) {
    try {
        // Get the available debug configurations
        const debugConfigurations = vscode.workspace.getConfiguration('launch').get<vscode.DebugConfiguration[]>('configurations');

        // Find the configuration with the specified name
        const config = debugConfigurations?.find(c => c.name === configName);

        if (config) {
             // Optionally, set this configuration as the active one.
            // This is a workaround; VS Code doesn't have a direct API to set the active config.
            // You might need to save and restore the launch.json file to achieve this reliably.
            // This part is tricky and might not be perfectly reliable.
            const launchConfig = vscode.workspace.getConfiguration('launch');
            const originalConfigurations = launchConfig.get('configurations');
            await launchConfig.update('configurations', [config], vscode.ConfigurationTarget.Workspace);


            // Start debugging with the found configuration
            await vscode.commands.executeCommand('workbench.action.debug.start');

            // Restore the original configurations (Important!)
            await launchConfig.update('configurations', originalConfigurations, vscode.ConfigurationTarget.Workspace);
            vscode.window.showInformationMessage(`Debugging started with configuration: ${configName}`);
        } else {
            vscode.window.showErrorMessage(`Debug configuration not found: ${configName}`);
        }
    } catch (error:any) {
        vscode.window.showErrorMessage(`Failed to start debugging: ${error.message}`);
    }
}