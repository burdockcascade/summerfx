function main()

    local screenWidth = 800
    local screenHeight = 450

    Window.Init(screenWidth, screenHeight, "raylib [core] example - input mouse wheel")

    local boxPositionY = screenHeight/2 - 40
    local scrollSpeed = 4

    Window.SetTargetFPS(60)

    while not Window.ShouldClose() do

        boxPositionY = boxPositionY - (Input.GetMouseWheelMove() * scrollSpeed)

        Window.BeginDrawing();

            Window.ClearBackground(COLOR_RAYWHITE)

            Graphics2D.DrawRectangle(screenWidth/2 - 40, boxPositionY, 80, 80, COLOR_MAROON)

            Graphics2D.DrawText("Use mouse wheel to move the cube up and down!", 10, 10, 20, COLOR_GRAY)
            Graphics2D.DrawText(TextFormat("Box position Y: %03i", boxPositionY), 10, 40, 20, LIGHTGRAY)

        Window.EndDrawing()
    end

    Window.CloseWindow();

end

main()
