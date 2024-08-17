Window.Open("Demo App", 800, 600)

local oceanblue = Color(0, 105, 148, 255)
local white = Color(255, 255, 255, 255)

while Window.IsOpen() do

    Window.BeginDrawing()

    Window.ClearBackground(oceanblue)

    Window.DrawFPS(10, 10)

    Graphics2D.DrawText("Hello, World!", 10, 40, 20, white)

    Window.EndDrawing()

end

Window.Close()