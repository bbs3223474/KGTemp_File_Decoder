# KGTemp_File_Decoder
由于酷狗使用了.kgtemp格式作为其音乐的缓存文件，并对该文件一部分进行4字节循环加密，使得其它音频播放器无法识别和播放该格式。本程序用于解密.kgtemp文件，并输出.flac文件，使其能够被普通播放器读取。

English Version:
Due to the Kugou Music Player (a music player for Chinese users) uses .kgtemp as its own music buffering file format, and 4-bit encrypted part of it, we cannot read those files by common music player softwares. This program is used to decrypt those .kgtemp files and output .flac files, so they can be read by any players.

注意：
1、本程序使用tcc编译，仅需要下载tcc然后执行CompileTCC.bat即可完成编译，输出exe位于项目tcc目录下。（你可能需要对该bat进行适当修改以完成编译）
2、本程序源代码参考自：http://www.cnblogs.com/KMBlog/p/6877752.html ，由huaying1988.com修改和首次编译，由bbs3223474（本人）汉化，感谢作者的大力支持！
3、如果你想使用英文版本，请编译项目下的decodeKg_ENG.c
4、本程序仅为临时解密一个.flac文件而编译，它本身不具备判断.kgtemp对应的音频格式的能力，因此你需要自己判断源文件到底是.mp3还是.flac或者是其他的格式，然后对它的后缀名进行修改。若有能力编写判断代码，欢迎各位提交自己的Pull request。

NOTICE:
1. This project was compiled by TCC, you only have to download TCC and run CompileTCC.bat under the project folder to finish the compilation. The program itself will be placed under tcc folder. (You may have to do some changes to the bat file to complete this job.)
2. Source code references to http://www.cnblogs.com/KMBlog/p/6877752.html , edited and first compiled by huaying1988.com, Chinese localized by bbs3223474 (me). Thanks to everybody!
3. If you want to use English version, please compile decodeKg_ENG.c under the project folder.
4. This program is only used to decode a .flac file by temporary. The program itself cannot understand which audio format it should corresponds to. So you have to judge the format of the source files, wether the .mp3 or .flac and other formats, then edit the suffix by yourself. If anyone can write some codes that be able to know the audio format, please send me a pull request.
