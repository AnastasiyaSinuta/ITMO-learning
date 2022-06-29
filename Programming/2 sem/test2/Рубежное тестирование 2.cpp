DecStr operator + (const DecStr& pobj1, const int pobj2)
{
	int num1, num2;
	DecStr tmp(pobj1);
	num1 = atoi(tmp.GetStr());
	num2 = pobj2;
	long long int A = long long(num1) + num2;
	if (A < -2147483648 || A > 2147483647)
	{
		delete[] tmp.pCh;
		tmp.len = 0;
		tmp.pCh = new char[tmp.len + 1];
		tmp.pCh[0] = '\0';
	}
	else
	{
		char* pTmpCh;
		int LenPobj2 = 0;
		int Pobj2_2 = pobj2;
		while (Pobj2_2 % 10 != 0)
		{
			Pobj2_2 = Pobj2_2 / 10;
			LenPobj2++;
		}
		if (tmp.len >= LenPobj2)
		{
			pTmpCh = new char[tmp.len + 2];
			_itoa_s(A, pTmpCh, tmp.len + 2, 10);
		}
		else
		{
			pTmpCh = new char[LenPobj2 + 2];
			_itoa_s(A, pTmpCh, LenPobj2 + 2, 10);
		}
		if (tmp.pCh) delete[] tmp.pCh;
		tmp.pCh = pTmpCh;
		tmp.len = strlen(tmp.pCh);
	}
	return tmp;
}