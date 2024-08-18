Window.Open("Demo App", 800, 600)

local skyblue = Color(135, 206, 235, 255)
local oceanblue = Color(0, 105, 148, 255)
local white = Color(255, 255, 255, 255)
local red = Color(255, 0, 0, 255)
local orange = Color(255, 127, 39, 255)

while Window.IsOpen() do

    Window.BeginDrawing()

    Window.ClearBackground(oceanblue)

    Window.DrawFPS(10, 10)

    -- draw text
    Graphics2D.DrawText("Hello, World!", Vector2(10, 40), 20, white)
    Graphics2D.DrawText("Press ESC to exit", Vector2(10, 60), 20, white)

    -- draw rectangle
    Graphics2D.DrawRectangle(Rectangle(10, 100, 100, 100), white)
    Graphics2D.DrawRectangleLines(Rectangle(30, 120, 100, 100), 5, red)
    Graphics2D.DrawRectangleRounded(Rectangle(10, 220, 100, 100), 0.1, 0, white)
    Graphics2D.DrawRectangleRoundedLines(Rectangle(30, 240, 100, 100), 0.1, 0, 5, red)
    Graphics2D.DrawRectangleGradientH(Rectangle(150, 140, 100, 100), orange, red)
    Graphics2D.DrawRectangleGradientV(Rectangle(150, 250, 100, 100), skyblue, oceanblue)
    Graphics2D.DrawRectangleGradientEx(Rectangle(270, 140, 100, 100), orange, red, skyblue, oceanblue)

    -- draw poly
    Graphics2D.DrawPoly(Vector2(400, 100), 8, 50, 0, skyblue)

    -- draw screen width
    local width = Window.GetWidth()
    Graphics2D.DrawText("Screen Width: " .. width, Vector2(10, 350), 20, white)

    -- draw screen height
    local height = Window.GetHeight()
    Graphics2D.DrawText("Screen Height: " .. height, Vector2(10, 370), 20, white)

    -- draw boolean for fullscreen
    local fullscreen = Window.IsFullscreen()
    Graphics2D.DrawText("Fullscreen: " .. tostring(fullscreen), Vector2(10, 390), 20, white)

    -- is window focused
    local focused = Window.IsFocused()
    Graphics2D.DrawText("Focused: " .. tostring(focused), Vector2(10, 410), 20, white)

    -- draw window position
    local pos = Window.GetPosition()
    Graphics2D.DrawText("Window Position: " .. pos.x .. ", " .. pos.y, Vector2(10, 430), 20, white)

    Window.EndDrawing()

end

Window.Close()