echo -n "{\"configurations\": [{\"name\": \"(gdb) 启动\",\"type\": \"cppdbg\",\"request\": \"launch\",\"program\": \"\${workspaceFolder}/" >.vscode/launch.json
echo -n $1 >> .vscode/launch.json
echo -n "\",\"args\": [],\"stopAtEntry\": false,\"cwd\": \"\${fileDirname}\",\"environment\": [],\"externalConsole\": false,\"MIMode\": \"gdb\",\"setupCommands\": [{    \"description\": \"为 gdb 启用整齐打印\", \"text\": \"-enable-pretty-printing\",\"ignoreFailures\": true},{\"description\": \"将反汇编风格设置为 Intel\",\"text\": \"-gdb-set disassembly-flavor intel\",\"ignoreFailures\": true}]}]}" >>.vscode/launch.json

