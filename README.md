create the dll:  
  g++ -shared -o main.dll main.cpp -lws2_32

excetute the dll on cmd directly:  
  regsvr32.exe main.dll

convert ico(loader.rc) to loader.res:  
  windres loaderr.rc -O coff -o loaderr.res

convert the program(loader.cpp) to loader.exe:  
  g++ loaderr.cpp loaderr.res -o loaderr.exe -mwindows

  that's all folks! =)
