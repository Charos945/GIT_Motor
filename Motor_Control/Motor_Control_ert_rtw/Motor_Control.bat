
call "setup_msvc.bat"


call  "\\'hostname' �����ڲ����ⲿ���Ҳ���ǿ����еĳ���
���������ļ���\D$\Program Files\Polyspace\R2020b\bin\win64\checkMATLABRootForDriveMap.exe" "\\'hostname' �����ڲ����ⲿ���Ҳ���ǿ����еĳ���
���������ļ���\D$\Program Files\Polyspace\R2020b"  > mlEnv.txt
for /f %%a in (mlEnv.txt) do set "%%a"\n
cd .

if "%1"=="" (nmake MATLAB_ROOT=%MATLAB_ROOT% ALT_MATLAB_ROOT=%ALT_MATLAB_ROOT% MATLAB_BIN=%MATLAB_BIN% ALT_MATLAB_BIN=%ALT_MATLAB_BIN%  -f Motor_Control.mk all) else (nmake MATLAB_ROOT=%MATLAB_ROOT% ALT_MATLAB_ROOT=%ALT_MATLAB_ROOT% MATLAB_BIN=%MATLAB_BIN% ALT_MATLAB_BIN=%ALT_MATLAB_BIN%  -f Motor_Control.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1