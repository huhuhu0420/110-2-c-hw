#include <stdio.h>
#include <math.h>

int type183(int data[5]){
    double money;
    money = 0.08*data[0] + 0.1393*data[1] + 0.1349*data[2] + 1.1287*data[3] + 1.4803*data[4];
    money = round(money);
    money = (183 > money) ? 183:money;
    return money;
}

int type383(int data[5]){
    double money;
    money = 0.07*data[0] + 0.1304*data[1] + 0.1217*data[2] + 1.1127*data[3] + 1.2458*data[4];
    money = round(money);
    money = (383 > money) ? 383:money; 
    return money;
}

int type983(int data[5]){
    double money;
    money = 0.06*data[0] + 0.1087*data[1] + 0.1018*data[2] + 0.9572*data[3] + 1.1243*data[4];
    money = round(money);
    money = (983 > money) ? 983:money; 
    return money;
}

int main(){
    int data[5], m183, m383, m983, minId, minMoney;
    scanf("%d %d %d %d %d", &data[0], &data[1], &data[2], &data[3], &data[4]);
    m183 = type183(data);
    m383 = type383(data);
    m983 = type983(data);
    //printf("%d %d %d\n", m183, m383, m983); 
    if(m183 < m383){
        minId = 183;
        minMoney = m183;
    }
    else{
        minId = 383;
        minMoney = m383;
    }
    if(minMoney > m983){
        minId = 983;
        minMoney = m983;
    }
    
    printf("%d", minId);

    return 0; 
}
