#include <windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	OPENFILENAME ofn;
	TCHAR szOpenFileNames[80 * MAX_PATH];
	TCHAR szPath[MAX_PATH];
	TCHAR szFileName[80 * MAX_PATH];
	TCHAR* p;
	int nLen = 0;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.Flags = OFN_EXPLORER | OFN_ALLOWMULTISELECT;
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szOpenFileNames;
	ofn.nMaxFile = sizeof(szOpenFileNames);
	ofn.lpstrFile[0] = '/0';
	ofn.lpstrFilter = TEXT("All Files(*.*)/0*.*/0");
	if (GetOpenFileName(&ofn))
	{
		//�ѵ�һ���ļ���ǰ�ĸ��Ƶ�szPath,��:
		//���ֻѡ��һ���ļ�,�͸��Ƶ����һ��'/'
		//���ѡ�˶���ļ�,�͸��Ƶ���һ��NULL�ַ�
		lstrcpyn(szPath, szOpenFileNames, ofn.nFileOffset);
		//��ֻѡ��һ���ļ�ʱ,�������NULL�ַ��Ǳ����.
		//���ﲻ����Դ�ѡ��һ���Ͷ���ļ������
		szPath[ofn.nFileOffset] = '/0';
		nLen = lstrlen(szPath);

		if (szPath[nLen - 1] != '//')   //���ѡ�˶���ļ�,��������'//'
		{
			lstrcat(szPath, TEXT("//"));
		}

		p = szOpenFileNames + ofn.nFileOffset; //��ָ���Ƶ���һ���ļ�

		ZeroMemory(szFileName, sizeof(szFileName));
		while (*p)
		{
			lstrcat(szFileName, szPath);  //���ļ�������·��  
			lstrcat(szFileName, p);    //�����ļ���  
			lstrcat(szFileName, TEXT("/n")); //����   
			p += lstrlen(p) + 1;     //������һ���ļ�
		}
		MessageBox(NULL, szFileName, TEXT("MultiSelect"), MB_OK);
	}
}
int main()
{
	OPENFILENAME ofn;
	TCHAR szOpenFileNames[80 * MAX_PATH];
	TCHAR szPath[MAX_PATH];
	TCHAR szFileName[80 * MAX_PATH];
	TCHAR* p;
	int nLen = 0;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.Flags = OFN_EXPLORER | OFN_ALLOWMULTISELECT;
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szOpenFileNames;
	ofn.nMaxFile = sizeof(szOpenFileNames);
	ofn.lpstrFile[0] = '/0';
	ofn.lpstrFilter = TEXT("All Files(*.*)/0*.*/0");

	if (GetOpenFileName(&ofn))
	{
		//�ѵ�һ���ļ���ǰ�ĸ��Ƶ�szPath,��:
		//���ֻѡ��һ���ļ�,�͸��Ƶ����һ��'/'
		//���ѡ�˶���ļ�,�͸��Ƶ���һ��NULL�ַ�
		lstrcpyn(szPath, szOpenFileNames, ofn.nFileOffset);
		//��ֻѡ��һ���ļ�ʱ,�������NULL�ַ��Ǳ����.
		//���ﲻ����Դ�ѡ��һ���Ͷ���ļ������
		szPath[ofn.nFileOffset] = '/0';
		nLen = lstrlen(szPath);

		if (szPath[nLen - 1] != '//')   //���ѡ�˶���ļ�,��������'//'
		{
			lstrcat(szPath, TEXT("//"));
		}

		p = szOpenFileNames + ofn.nFileOffset; //��ָ���Ƶ���һ���ļ�

		ZeroMemory(szFileName, sizeof(szFileName));
		while (*p)
		{
			lstrcat(szFileName, szPath);  //���ļ�������·��  
			lstrcat(szFileName, p);    //�����ļ���  
			lstrcat(szFileName, TEXT("/n")); //����   
			p += lstrlen(p) + 1;     //������һ���ļ�
		}
		MessageBox(NULL, szFileName, TEXT("MultiSelect"), MB_OK);
	}
	while (true)
	{

	}
	return 0;
}