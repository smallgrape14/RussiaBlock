
class  Render
{
private:
   int length;
   int width;
public:
void initialWindow(HANDLE hOut);//初始化窗口
void initialPrint(HANDLE hOut);//初始化界面
void set wall() //设置边框,用于检测碰撞 
void gotoXY(HANDLE hOut, int x, int y);//移动光标

}; 