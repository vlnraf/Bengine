#### TODO:
- [x] Initialize the game loop
- [x] Initialize the game loop using SDL to create a graphic window
- [x] Create a simple GameObject class
- [ ] Create a simple renderer:
    - [x] Create a simple Texture Manager that draw rectangles
- [ ] Probably The handles should be decoupled so i have to create a new class:
    The reason is that if i create a new gameObject Player2 i have to copy paste all the code in Player1 to Player2
- [x] Player movements
- [x] Ball movement
- [x] Add collision
- [ ] I should calculate phisycs and rendering in different ways because now if the app goes at slow fps it does not calculate the collision correctly
- [ ] CollisionManager should return where the objects have intersected so the object can do different acionts based on that infomation 
(example: if the ball hit the top part of the paddle increase also yvel so the ball start moving diagonal)