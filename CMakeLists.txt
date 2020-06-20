cmake_minimum_required(VERSION 3.15)
project(SpaceInvaders)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR/cmake})
set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(SpaceInvaders
			  	main.cpp

				GameConstants.h
				GameConstants.cpp
			  	Game.cpp
		      	Game.h

				Settings.cpp
				Settings.h

				Factories/Factory.cpp
				Factories/Factory.h
				Sdl/Factories/SDLFactory.cpp
				Sdl/Factories/SDLFactory.h
				Factories/UIFactory.cpp
				Factories/UIFactory.h
				Sdl/Factories/SDLUIFactory.cpp
				Sdl/Factories/SDLUIFactory.h

        		Windows/Window.cpp
        		Windows/Window.h
				Sdl/Window/SDLWindow.cpp
				Sdl/Window/SDLWindow.h

				Color.cpp
				Color.h

				Events/EventHandler.cpp
				Events/EventHandler.h
		Events/EventListener.h

				AssetLoaders/Sprites/SpriteLoader.cpp
				AssetLoaders/Sprites/SpriteLoader.h
				AssetLoaders/Sprites/Sprite.cpp
				AssetLoaders/Sprites/Sprite.h
				AssetLoaders/FontLoader.cpp
				AssetLoaders/FontLoader.h
        		AssetLoaders/Audio/AudioLoader.cpp
				AssetLoaders/Audio/AudioLoader.h
		AssetLoaders/Audio/AudioClip.h
		AssetLoaders/Audio/Music.h

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
				GameObjects/Bonus.cpp
				GameObjects/Bonus.h

				Sdl/AssetLoaders/Sprites/SDLSpriteLoader.cpp
				Sdl/AssetLoaders/Sprites/SDLSpriteLoader.h
				Sdl/AssetLoaders/Sprites/SDLSprite.cpp
				Sdl/AssetLoaders/Sprites/SDLSprite.h
				Sdl/AssetLoaders/SDLFontLoader.cpp
				Sdl/AssetLoaders/SDLFontLoader.h
				Sdl/AssetLoaders/Audio/SDLMusic.cpp
				Sdl/AssetLoaders/Audio/SDLMusic.h
				Sdl/AssetLoaders/Audio/SDLAudioLoader.cpp
				Sdl/AssetLoaders/Audio/SDLAudioLoader.h
				Sdl/AssetLoaders/Audio/SDLAudioClip.cpp
				Sdl/AssetLoaders/Audio/SDLAudioClip.h

				UI/UIComponent.h
				UI/UIComponent.cpp
				UI/Text.cpp
				UI/Text.h
				UI/Button.cpp
				UI/Button.h
				Sdl/UI/SDLText.cpp
				Sdl/UI/SDLText.h

				Scenes/Scene.cpp
				Scenes/Scene.h
				Scenes/GameScene.cpp
				Scenes/GameScene.h
				Scenes/LoadScene.cpp
				Scenes/LoadScene.h
				Scenes/GameOverScene.cpp
				Scenes/GameOverScene.h
				Scenes/MenuScene.cpp
				Scenes/MenuScene.h

				Controllers/GameController.cpp
				Controllers/GameController.h

				GameObjects/Bullet.cpp
				GameObjects/Bullet.h
				Utils/Timer.cpp
				Utils/Timer.h
				Utils/FunctionDefinitions.h
				Utils/Math.cpp
				Utils/Math.h
				Utils/Random.cpp
				Utils/Random.h
				Sdl/Utils/SDLTimer.cpp
				Sdl/Utils/SDLTimer.h)


target_link_libraries(SpaceInvaders ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)