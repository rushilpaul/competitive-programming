set obj = createobject("scripting.filesystemobject")
set wshell = createobject("wscript.shell")
file = inputbox("Enter filename of file to be created:","File Creation")
if file = "" then
wscript.quit(1)
end if

if obj.fileexists(file) then
msgbox "File already exists",48,"Error"
wshell.run("notepad++ " & file)
wscript.quit(2)
end if

set objfile = obj.createTextFile(file,false)
msgbox "File created!",64,"File Creation"
wshell.run("notepad++ " & file)