@echo off
title ת����ǰĿ¼������.kgtemp�ļ�
color 5E
echo ===============================================================
echo ת����ǰĿ¼������.kgtemp�ļ�
echo decodeKg.exe�ο���http://www.cnblogs.com/KMBlog/p/6877752.html
echo                  ����written by huaying1988.com (201706280110)
echo ================================================================
echo ׼��ת����%~dp0��Ŀ¼������.kgtemp�ļ�
echo ��˶ԡ�%~dp0��Ŀ¼�Ƿ���ȷ��Ȼ�����������������ֱ�ӹص����ڣ�
pause
for %%i in (*.kgtemp) do (
	echo ת���ļ�:%%i
	decodeKg.exe "%%i"
)
echo ת����ɣ������������
pause