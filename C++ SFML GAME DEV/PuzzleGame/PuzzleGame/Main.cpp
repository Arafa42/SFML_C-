#include <SFML/Graphics.hpp>
#include <iostream>


int main() {

    //WINDOW 
    sf::RenderWindow app(sf::VideoMode(256,256), "PUZZLE GAME");
    app.setFramerateLimit(60);

    //AFBEELDING
    sf::Texture t;
    t.loadFromFile("images/puzzle.png");

    //GRID
    int w = 64;
    int grid[6][6] = { 0 };
    sf::Sprite sprite[20];
      
        int n = 0;
        for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            n++;
            sprite[n].setTexture(t);
            sprite[n].setTextureRect(sf::IntRect(i*w,j*w,w,w));
            grid[i + 1][j+1] = n;
        }


        while (app.isOpen()) {

            //EVENT MOUSE CLICK
            sf::Event e;
            while (app.pollEvent(e)) {

                if (e.type == sf::Event::Closed) {
                    app.close();
                }

                if (e.type == sf::Event::MouseButtonPressed) {
                    if (e.key.code == sf::Mouse::Left) {

                        sf::Vector2i pos = sf::Mouse::getPosition(app);

                        int x = pos.x / w + 1;
                        int y = pos.y / w + 1;


                        if (x == 4 && y == 4) { std::cout << std::endl << "YOU WIN" << std::endl << std::endl; }



                        int dx = 0;
                        int dy = 0;

                        if (grid[x + 1][y] == 16) { dx = 1; dy = 0; }
                        if (grid[x][y+1] == 16) { dx = 0; dy = 1; }
                        if (grid[x - 1][y] == 16) { dx = -1; dy = 0; }
                        if (grid[x][y - 1] == 16) { dx = 0; dy = -1; }

                        int n = grid[x][y];

                        std::cout << "x "  << x  << std::endl;
                        std::cout << "y "  << y  << std::endl;
                        std::cout << "n "  << n  << std::endl;
                        std::cout << "dx " << dx << std::endl;
                        std::cout << "dy " << dy << std::endl;
                     

                        grid[x][y] = 16;
                        grid[x + dx][y + dy] = n;

                        //ANIMATIES
                        sprite[16].move(-dx * w, -dy * w);
                        float speed = 3;

                        for (int i = 0; i < w; i += speed) {

                            sprite[n].move(speed * dx, speed * dy);
                            app.draw(sprite[16]);
                            app.draw(sprite[n]);
                            app.display();

                        }       
                    }
                }
            }

            app.clear(sf::Color::White);

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {                 
                    int n = grid[i+1][j+1];
                    sprite[n].setPosition(i * w, j * w);                
                    app.draw(sprite[n]);
                   
                }
            }
            app.display();
        
      
          

        
        }

    return 0;
}