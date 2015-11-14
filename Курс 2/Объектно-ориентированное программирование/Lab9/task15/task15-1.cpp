/* В  21
   Файл целых положительных чисел. Сортировка: сначала числа, делящиеся на 4 в порядке возрастания,
   потом нечетные в порядке убывания и далее оставшиеся четные в порядке возрастания. Удалить нечетные числа, делящиеся на 3.
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
bool psz(int i, int j)
{
	
	if(i % 4 != 0  && j % 4!=0 ){
		if(i % 2 != 0 && j %2 !=0)
			return i > j;
		else if(i % 2 !=0)
			return true;
		else if(j % 2 !=0)
			return false;
		return i < j;
	}else if(i % 4 != 0)
		return false;
	else if(j % 4 != 0)
		return true;
 	return i < j;
}
void Print(const vector<int>& v);
int main()
{
	vector <int> v1;
	vector <int> v2;
	int tmp;
	v1.clear();
	fstream test("test.txt", ios_base::in);
	
	while(test >> tmp)
		v1.push_back(tmp);
	Print(v1);
	sort(v1.begin(), v1.end(),psz );
	Print(v1);	
	for(int i = 0; i < v1.size(); i++)
		if(v1[i] % 3 ==0 && v1[i] % 2 !=0){
			v2.push_back(v1[i]);
			v1.erase(v1.begin() + i);
		}
	Print(v1);	
	Print(v2);	
	return 0;
}

void Print(const vector<int>& v)
{
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	
}
