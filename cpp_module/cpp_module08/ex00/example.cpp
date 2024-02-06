#include <iostream>

/**
 * Q) 내가 궁금했던 것: 함수의 매개변수로 const T&, T&, T의 차이?
 *                   또, 상수가 위의 경우 중 const T&와 T로 정의되어 있는 경우만 대입 가능 왜?
 * A) T: pass by value: 원래의 값을 변화시키지 않으면서 전달된 값을 복사 생성하여 함수 내부에서 사용 >> 상수 가능
 *    const T&: pass by const-referenc: 원래의 값을 변화시키지 않으면서 전달된 값을 그대로 함수 내부에서 시용하되, 원래의 값에 참조하여 변형하지 않음 >> 상수 가능
 *    T&: pass by reference: 원래의 값을 참조하여 변형할 수 있다는 원칙 하에 해당 값 자체를 참조하여 함수 내부에서 사용 >> 상수는 참조가 불가능하므로 안됨!!!
*/

template<typename T>
T add(T a, T b) {
    return a + b;
}

int main(void) {
    int res = 0;
    std::cout << add(1.0, 3.0) << std::endl;

    // int a = 1, b = 3;
    // res = add(a, b);

    std::cout << "results: " << res << std::endl;
}
