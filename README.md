# Snake in C++

This is a small project I wrote to practice my C++ skills and object oriented programming. It's a recreation of the classic game Snake.

The game consists of a title screen with two modes, easy and hard. The easy mode allows the snake to wrap around, whilst the hard mode returns game over if the snake exceeds the screen bounds. The game otherwise functions just like the original - if the snake self-intersects, it dies, and the goal is to maximise the score by eating increasing amounts of food and making the snake as long as you can.

Each class has its own header file, and the header file has the specification for each class. It lists out the member variables and methods that are implemented by the class. To see the implementation, just go to the corresponding `.cpp` file. For example, the `Game` class has a header `Game.h` which contains its definition, and an implementation in `Game.cpp`.

The project was built in Visual Studio, and coded entirely in C++, using the `RayLib` library. `RayLib` makes rendering simple, allowing programmers to focus on the game logic.
