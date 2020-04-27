cmake_minimum_required(VERSION 3.15)
project(SpaceInvaders)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR/cmake})
set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(SpaceInvaders
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
		Sdl/UI/SDLText.cpp
		Sdl/UI/SDLText.h Scenes/Scene.cpp Scenes/Scene.h UI/UIComponent.h UI/UIComponent.cpp AssetLoaders/Sprites/SpriteMap.cpp AssetLoaders/Sprites/SpriteMap.h Controllers/GameController.cpp Controllers/GameController.h Scenes/GameScene.cpp Scenes/GameScene.h Scenes/LoadScene.cpp Scenes/LoadScene.h GameObjects/Bullet.cpp GameObjects/Bullet.h Utils/Timer.cpp Utils/Timer.h Scenes/GameOverScene.cpp Scenes/GameOverScene.h UI/Button.cpp UI/Button.h Utils/FunctionDefinitions.h Factories/UIFactory.cpp Factories/UIFactory.h Sdl/Factories/SDLUIFactory.cpp Sdl/Factories/SDLUIFactory.h Utils/Math.cpp Utils/Math.h Utils/Random.cpp Utils/Random.h Sdl/Utils/SDLTimer.cpp Sdl/Utils/SDLTimer.h GameObjects/Bonus.cpp GameObjects/Bonus.h Settings.cpp Settings.h Scenes/MenuScene.cpp Scenes/MenuScene.h GameConstants.cpp)


target_link_libraries(SpaceInvaders ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)