```markdown
Create the DLL:  
`g++ -shared -o main.dll main.cpp -lws2_32`

Execute the DLL on CMD directly:  
`regsvr32.exe main.dll`

Convert ico (loader.rc) to loader.res:  
`windres loaderr.rc -O coff -o loaderr.res`

Convert the program (loader.cpp) to loader.exe:  
`g++ loaderr.cpp loaderr.res -o loaderr.exe -mwindows`

The video making of: https://www.youtube.com/watch?v=gEU9hPCHp14&t=1032s

That's all folks! =)
