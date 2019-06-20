int e = 6;
float r = 0.3;
void main() {
	int b = 5;
	int g = 0;
	g++;
	int f = --b;
	float t2 = g % b;
	print(g); // 1
	f = b + 5 + g++; // 4+5+1
	print(f); // 10
	print(g); // 2
	int tt;
	tt = g++;
	print(tt); // 2
	e++;
	print(e); // 7
    return;
}

