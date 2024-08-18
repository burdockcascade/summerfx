Window.Init("Demo App", 800, 600)

local skyblue <const> = Color(135, 206, 235, 255)
local oceanblue <const> = Color(0, 105, 148, 255)
local white <const> = Color(255, 255, 255, 255)
local red <const> = Color(255, 0, 0, 255)
local orange <const> = Color(255, 127, 39, 255)

while not Window.ShouldClose() do

    Window.BeginDrawing()

    Window.ClearBackground(oceanblue)

    Window.DrawFPS(10, 10)

    -- draw text
    Graphics2D.DrawText("Hello, World!", Vector2(10, 40), 20, white)
    Graphics2D.DrawText("Press ESC to exit", Vector2(10, 60), 20, white)

    -- draw pixel
    Graphics2D.DrawPixel(Vector2(400, 80), white)

    -- draw line
    Graphics2D.DrawLine(Vector2(10, 80), Vector2(110, 80), orange)

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

    -- draw circle
    Graphics2D.DrawCircle(Vector2(400, 200), 50, red)
    Graphics2D.DrawCircleLines(Vector2(400, 200), 50, red)
    Graphics2D.DrawCircleSector(Vector2(550, 200), 50, 0, 180, 50, skyblue)
    Graphics2D.DrawCircleSectorLines(Vector2(550, 200), 50, 0, 180, 5, red)
    Graphics2D.DrawCircleGradient(Vector2(400, 350), 50, orange, red)


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

    -- draw mouse position
    local mousePos = Window.GetMousePosition()
    Graphics2D.DrawText("Mouse Position: " .. mousePos.x .. ", " .. mousePos.y, Vector2(10, 450), 20, white)

    -- draw elapsed time
    local elapsed = Window.GetElapsedTime()
    Graphics2D.DrawText("Elapsed Time: " .. elapsed, Vector2(10, 470), 20, white)

    -- draw frame time
    local frameTime = Window.GetFrameTime()
    Graphics2D.DrawText("Frame Time: " .. frameTime, Vector2(10, 490), 20, white)

    -- print mouse wheel
    local wheel = Input.GetMouseWheelMove()
    Graphics2D.DrawText("Mouse Wheel: " .. wheel, Vector2(10, 510), 20, white)


    Window.EndDrawing()

end

Window.Close()