cmake_minimum_required(VERSION 3.15)
project(Game)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR/cmake})
set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(Game
			  	main.cpp

				GameConstants.h
			  	Game.cpp
		      	Game.h

				Factories/Factory.cpp
				Factories/Factory.h

        		Windows/Window.cpp
        		Windows/Window.h

				Color.cpp
				Color.h

				Events/EventHandler.cpp
				Events/EventHandler.h
				Events/EventListener.cpp
				Events/EventListener.h

				AssetLoaders/Sprites/SpriteLoader.cpp
				AssetLoaders/Sprites/SpriteLoader.h
				AssetLoaders/Sprites/Sprite.cpp
				AssetLoaders/Sprites/Sprite.h
				AssetLoaders/FontLoader.cpp
				AssetLoaders/FontLoader.h

		Controllers/LevelController.cpp
		Controllers/LevelController.h
				Controllers/EnemyController.cpp
				Controllers/EnemyController.h

				GameObjects/GameObject.cpp
				GameObjects/GameObject.h
				GameObjects/Player.cpp
				GameObjects/Player.h
				GameObjects/Alien.cpp
				GameObjects/Alien.h


			   	Sdl/Factories/SDLFactory.cpp
			   	Sdl/Factories/SDLFactory.h
			   	Sdl/Window/SDLWindow.cpp
			   	Sdl/Window/SDLWindow.h

				Sdl/AssetLoaders/Sprites/SDLSpriteLoader.cpp
				Sdl/AssetLoaders/Sprites/SDLSpriteLoader.h
				Sdl/AssetLoaders/Sprites/SDLSprite.cpp
				Sdl/AssetLoaders/Sprites/SDLSprite.h
				Sdl/AssetLoaders/SDLFontLoader.cpp
				Sdl/AssetLoaders/SDLFontLoader.h
		UI/Text.cpp
		UI/Text.h
				Sdl/AssetLoaders/Sprites/SDLText.cpp
				Sdl/AssetLoaders/Sprites/SDLText.h Scenes/Scene.cpp Scenes/Scene.h UI/UIComponent.h UI/UIComponent.cpp AssetLoaders/Sprites/SpriteMap.cpp AssetLoaders/Sprites/SpriteMap.h Controllers/GameController.cpp Controllers/GameController.h)


target_link_libraries(Game ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)