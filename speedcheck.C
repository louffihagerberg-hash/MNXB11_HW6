#include <iostream>
#include "MovingObject.h"

void speedcheck()
{
    MovingObject obj;
    obj.SetVelocity(0.3, 0.4, 0.0);

    std::cout << "Vx = " << obj.Vx() << '\n';
    std::cout << "Vy = " << obj.Vy() << '\n';
    std::cout << "Vz = " << obj.Vz() << '\n';
    std::cout << "Total speed = " << obj.Speed() << '\n';
    std::cout << "Horizontal speed = "
              << obj.HorizontalSpeed() << '\n';

    obj.SetVelocity(0.3, 0.4, 0.5);

    std::cout << "Vx = " << obj.Vx() << '\n';
    std::cout << "Vy = " << obj.Vy() << '\n';
    std::cout << "Vz = " << obj.Vz() << '\n';
    std::cout << "Total speed = " << obj.Speed() << '\n';
    std::cout << "Horizontal speed = "
              << obj.HorizontalSpeed() << '\n';

}