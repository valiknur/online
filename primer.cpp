void CDegreePlynomial::Init()
{
	int bYouA����� = 0;
	std::string bigString = "";
	do
	{
		bigString = "";
		CLEARCONSOLE;
		size = Vvod<size_t>("������� ���������� ���������� �� 1 �� 9", [](size_t a) {return a > 0 || a < 10; });
		std::cout << "������� " << size << " ��������\n";
		double delta;
		for (size_t i = 0; i < size; i++)
		{
			delta = Vvod<double>();
			this->arr.push_back(delta);
		}
		__super::Init();

		bigString += "\n" + std::to_string(arr[0]);
		for (size_t i = 1; i < size; i++)
		{
			bigString += (arr[i] < 0 ? " - " : " + ") + std::to_string(abs(arr[i])) + "*x^" + std::to_string(i);
		}
		bigString += "\n���������� ������������ ���������� = [" + std::to_string(leftIntegr) + ";" + std::to_string(rightIntegr) + "]\n";
		bYouA����� = Change(
			{
				{[]() {return 1; } ,"��"},
				{[]() {return 2; } ,"���"},
			},
			NONEEXIT | ONETIME,
			std::string(bigString + "�� �������� � ��������������� �������?"));
	} while (bYouA����� != 1);
}