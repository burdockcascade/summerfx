--******************************************************************************************
--
--   raylib [core] example - 2D Camera system
--
--   Example originally created with raylib 1.5, last time updated with raylib 3.0
--
--   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
--   BSD-like license that allows static linking with closed source software
--
--   Copyright (c) 2016-2024 Ramon Santamaria (@raysan5)
--
--******************************************************************************************

MAX_BUILDINGS = 100

--------------------------------------------------------------------------------------
-- Program main entry point
--------------------------------------------------------------------------------------
function main()

    -- Initialization
    ----------------------------------------------------------------------------------------
    local screenWidth = 800;
    local screenHeight = 450;

    Window.Init(screenWidth, screenHeight, "raylib [core] example - 2d camera");

    local player = Rectangle( 400, 280, 40, 40 );
    buildings = {}
    buildColors = {}

    local spacing = 0;

    for i = 1, MAX_BUILDINGS do
        buildings[i] = Rectangle(0, 0, 0, 0)
        buildings[i].width = RMath.GetRandomValue(50, 200)
        buildings[i].height = RMath.GetRandomValue(100, 800)
        buildings[i].y = screenHeight - 130.0 - buildings[i].height
        buildings[i].x = -6000.0 + spacing

        spacing = spacing + buildings[i].width

        buildColors[i] = Color(RMath.GetRandomValue(200, 240), RMath.GetRandomValue(200, 240), RMath.GetRandomValue(200, 250), 255)
    end

    local camera = Camera2D()
    camera.target = Vector2(player.x + 20, player.y + 20)
    camera.offset = Vector2(screenWidth/2, screenHeight/2)
    camera.rotation = 0.0
    camera.zoom = 1.0

    Window.SetTargetFPS(60);                   -- Set our game to run at 60 frames-per-second
    ----------------------------------------------------------------------------------------

    -- Main game loop
    while not Window.ShouldClose() do        -- Detect window close button or ESC key

        -- Update
        ------------------------------------------------------------------------------------
        -- Player movement
        if (Input.IsKeyDown(KEY_RIGHT)) then player.x = player.x + 2;
        elseif (Input.IsKeyDown(KEY_LEFT)) then player.x = player.x - 2;
        end

        -- Camera target follows player
        camera.target = Vector2( player.x + 20, player.y + 20 );

        -- Camera rotation controls
        if (Input.IsKeyDown(KEY_A)) then camera.rotation = camera.rotation - 1;
        elseif (Input.IsKeyDown(KEY_S)) then camera.rotation = camera.rotation + 1;
        end

        -- Limit camera rotation to 80 degrees (-40 to 40)
        if (camera.rotation > 40) then camera.rotation = 40;
        elseif (camera.rotation < -40) then camera.rotation = -40; end

        -- Camera zoom controls
        camera.zoom = camera.zoom + (Input.GetMouseWheelMove()* 0.05);

        if (camera.zoom > 3.0) then camera.zoom = 3.0;
        elseif (camera.zoom < 0.1) then camera.zoom = 0.1;
        end

        -- Camera reset (zoom and rotation)
        if Input.IsKeyPressed(KEY_R) then
            camera.zoom = 1.0;
            camera.rotation = 0.0;
        end
        ------------------------------------------------------------------------------------

        -- Draw
        ------------------------------------------------------------------------------------
        Window.BeginDrawing();

            Window.ClearBackground(COLOR_RAYWHITE);

            Window.BeginMode2D(camera);

                Graphics2D.DrawRectangle(-6000, 320, 13000, 8000, COLOR_DARKGRAY);

                for i = 1, MAX_BUILDINGS do
                    Graphics2D.DrawRectangleRec(buildings[i], buildColors[i]);
                end

                Graphics2D.DrawRectangleRec(player, COLOR_RED);

                Graphics2D.DrawLine(camera.target.x, -screenHeight*10, camera.target.x, screenHeight*10, COLOR_GREEN);
                Graphics2D.DrawLine(-screenWidth*10, camera.target.y, screenWidth*10, camera.target.y, COLOR_GREEN);

            Window.EndMode2D();

            Graphics2D.DrawText("SCREEN AREA", 640, 10, 20, COLOR_RED);

            Graphics2D.DrawRectangle(0, 0, screenWidth, 5, COLOR_RED);
            Graphics2D.DrawRectangle(0, 5, 5, screenHeight - 10, COLOR_RED);
            Graphics2D.DrawRectangle(screenWidth - 5, 5, 5, screenHeight - 10, COLOR_RED);
            Graphics2D.DrawRectangle(0, screenHeight - 5, screenWidth, 5, COLOR_RED);

            --Graphics2D.DrawRectangle( 10, 10, 250, 113, Fade(SKYBLUE, 0.5));
            Graphics2D.DrawRectangle( 10, 10, 250, 113, COLOR_SKYBLUE, 0.5);
            Graphics2D.DrawRectangleLines( 10, 10, 250, 113, COLOR_BLUE);

            Graphics2D.DrawText("Free 2d camera controls:", 20, 20, 10, COLOR_BLACK);
            Graphics2D.DrawText("- Right/Left to move Offset", 40, 40, 10, COLOR_DARKGRAY);
            Graphics2D.DrawText("- Mouse Wheel to Zoom in-out", 40, 60, 10, COLOR_DARKGRAY);
            Graphics2D.DrawText("- A / S to Rotate", 40, 80, 10, COLOR_DARKGRAY);
            Graphics2D.DrawText("- R to reset Zoom and Rotation", 40, 100, 10, COLOR_DARKGRAY);

        Window.EndDrawing();
        ------------------------------------------------------------------------------------
    end

    -- De-Initialization
    ----------------------------------------------------------------------------------------
    Window.Close();        -- Close window and OpenGL context
    ----------------------------------------------------------------------------------------

    return 0;
end

main()
