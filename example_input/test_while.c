void main(){
    int a = 1;
    while(a < 6){
        print("In while 0_0");
        a = a+1;
        while(a < 6){
            print("\tIn while 1_0");
            a = a+2;
        }
        a = 1;
        while(a < 6){
            print("\t\tIn while 1_1");
            a = a+3;
            while(a < 6){
                print("\t\t\tIn while 2_0");
                a = a+3;
            }
        }
    }
    a = 1;
    while(a < 6){
        print("In while 1_0");
        a = a+3;
        while(a < 6){
            print("\tIn while 2_0");
            a = a+3;
        }
    }
    return;
}
