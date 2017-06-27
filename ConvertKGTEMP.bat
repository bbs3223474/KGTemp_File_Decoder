@echo off
title 转换当前目录下所有.kgtemp文件
color 5E
echo ===============================================================
echo 转换当前目录下所有.kgtemp文件
echo decodeKg.exe参考自http://www.cnblogs.com/KMBlog/p/6877752.html
echo                  ——written by huaying1988.com (201706280110)
echo ================================================================
echo 准备转换“%~dp0”目录下所有.kgtemp文件
echo 请核对“%~dp0”目录是否正确，然后按任意键继续（否则直接关掉窗口）
pause
for %%i in (*.kgtemp) do (
	echo 转换文件:%%i
	decodeKg.exe "%%i"
)
echo 转换完成，按任意键结束
pause