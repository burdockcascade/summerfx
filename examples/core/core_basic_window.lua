local function main(void)

    local screenWidth = 800;
    local screenHeight = 450;

    Window.Init(screenWidth, screenHeight, "raylib [core] example - basic window");
    Window.SetTargetFPS(60)

    while not Window.ShouldClose() do

        Window.BeginDrawing()

            Window.ClearBackground(COLOR_RAYWHITE)

            Graphics2D.DrawText("Congrats! You created your first window!", 190, 200, 20, COLOR_LIGHTGRAY)

        Window.EndDrawing()

    end

    Window.Close()

end

main()
