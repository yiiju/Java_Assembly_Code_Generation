bool v = true;
bool f = false;
int e = 6;
float r = 0.3;
string b = "Hi";
int func() {
	return 5;
}
bool func2(bool a) {
	return a;
}
bool func3(bool a, string b) {
	return a;
}
void main() {
	int a = 1;
	int d = a + 6;
	int g = func();
	bool e = func2(true);
	string st = "ss";
	int y = func3(false, st);
	int b = g++;
	int l = --a;
	int t = 4 % 2;
    return;
}

