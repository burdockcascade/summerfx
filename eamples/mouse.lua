Window.Open("Demo App", 800, 600)

while Window.IsOpen() do

    Window.BeginDrawing()

    Window.ClearBackground(oceanblue)

    -- Get Mouse Position
    local mousePos = Window.GetMousePosition()
    Graphics2D.DrawText("Mouse Position: " .. mousePos.x .. ", " .. mousePos.y, Vector2(10, 10), 20, white)

    Window.EndDrawing()

end

Window.Close()