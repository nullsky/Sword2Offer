#include <iostream>
using namespace std;

class CSingleton
{
public:
	static CSingleton* Instance();

private:
	CSingleton();

	static CSingleton * m_pInstance;
};

CSingleton* CSingleton::m_pInstance = nullptr;

CSingleton::CSingleton()
{
}

CSingleton* CSingleton::Instance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new CSingleton();
	}
	return m_pInstance;
}

int main()
{
	CSingleton* sg1;
	CSingleton* sg2;
	CSingleton* sg3;
	sg1 = CSingleton::Instance();
	sg2 = CSingleton::Instance();
	sg3 = CSingleton::Instance();
	cout << sg1 << "\t" << sg2 << "\t" << sg3 << endl;
	system("pause");
	return 0;

}
