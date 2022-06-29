DecStr::DecStr(char ch) : Stroka(ch)
{
	if (!(pCh[0] >= '0' && pCh[0] <= '9'))
	{
		cout << "Bad symbol!, pCh[0] = " << pCh[0] << endl;
		if (pCh) delete[] pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return;
	}
	cout << "DecStr::DecStr(char ch) : Stroka(ch)" << endl;
}