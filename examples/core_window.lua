Window.Init("Demo App", 800, 600)

Window.SetTargetFPS(60)

local v2 = Vector2(10, 10)
local v3 = Vector3(10, 10, 10)
local v4 = Vector4(10, 10, 10, 10)

local camera2d = Camera2D(Vector2(0, 0), Vector2(0, 0), 0, 1)

while not Window.ShouldClose() do

    Window.BeginDrawing()

    Window.ClearBackground(COLOR_SKYBLUE)

    Graphics2D.DrawFPS(10, 10)

    -- draw text
    Graphics2D.DrawText("Raylib Version: " .. RAYLIB_VERSION, Vector2(10, 30), 20, COLOR_BLACK)
    Graphics2D.DrawText("Lua Version: " .. LUA_VERSION, Vector2(10, 50), 20, COLOR_BLACK)

    -- draw pixel
    Graphics2D.DrawPixel(Vector2(400, 80), COLOR_WHITE)

    -- draw line
    Graphics2D.DrawLine(Vector2(10, 80), Vector2(110, 80), COLOR_ORANGE)

    -- draw rectangle
    Graphics2D.DrawRectangle(Rectangle(10, 100, 100, 100), COLOR_WHITE)
    Graphics2D.DrawRectangleLines(Rectangle(30, 120, 100, 100), 5, COLOR_RED)
    Graphics2D.DrawRectangleRounded(Rectangle(10, 220, 100, 100), 0.1, 0, COLOR_WHITE)
    Graphics2D.DrawRectangleRoundedLines(Rectangle(30, 240, 100, 100), 0.1, 0, 5, COLOR_RED)
    Graphics2D.DrawRectangleGradientH(Rectangle(150, 140, 100, 100), COLOR_ORANGE, COLOR_RED)
    Graphics2D.DrawRectangleGradientV(Rectangle(150, 250, 100, 100), COLOR_BLUE, COLOR_PURPLE)
    Graphics2D.DrawRectangleGradientEx(Rectangle(270, 140, 100, 100), COLOR_ORANGE, COLOR_RED, COLOR_BLUE, COLOR_PURPLE)

    -- draw poly
    Graphics2D.DrawPoly(Vector2(400, 100), 8, 50, 0, COLOR_SKYBLUE)

    -- draw circle
    Graphics2D.DrawCircle(Vector2(400, 200), 50, COLOR_RED)
    Graphics2D.DrawCircleLines(Vector2(400, 200), 50, COLOR_RED)
    Graphics2D.DrawCircleSector(Vector2(550, 200), 50, 0, 180, 50, COLOR_SKYBLUE)
    Graphics2D.DrawCircleSectorLines(Vector2(550, 200), 50, 0, 180, 5, COLOR_RED)
    Graphics2D.DrawCircleGradient(Vector2(400, 350), 50, COLOR_ORANGE, COLOR_RED)


    -- draw screen width
    local width = Window.GetWidth()
    Graphics2D.DrawText("Screen Width: " .. width, Vector2(10, 350), 20, COLOR_WHITE)

    -- draw screen height
    local height = Window.GetHeight()
    Graphics2D.DrawText("Screen Height: " .. height, Vector2(10, 370), 20, COLOR_WHITE)

    -- is window focused
    local focused = Window.IsFocused()
    Graphics2D.DrawText("Focused: " .. tostring(focused), Vector2(10, 410), 20, COLOR_WHITE)

    -- draw window position
    local pos = Window.GetPosition()
    Graphics2D.DrawText("Window Position: " .. pos.x .. ", " .. pos.y, Vector2(10, 430), 20, COLOR_WHITE)

    -- draw mouse position
    local mousePos = Input.GetMousePosition()
    Graphics2D.DrawText("Mouse Position: " .. mousePos.x .. ", " .. mousePos.y, Vector2(10, 450), 20, COLOR_WHITE)

    -- draw elapsed time
    local elapsed = Window.GetElapsedTime()
    Graphics2D.DrawText("Elapsed Time: " .. elapsed, Vector2(10, 470), 20, COLOR_WHITE)

    -- draw frame time
    local frameTime = Window.GetFrameTime()
    Graphics2D.DrawText("Frame Time: " .. frameTime, Vector2(10, 490), 20, COLOR_WHITE)

    -- print mouse wheel
    local wheel = Input.GetMouseWheelMove()
    Graphics2D.DrawText("Mouse Wheel: " .. wheel, Vector2(10, 510), 20, COLOR_WHITE)


    Window.EndDrawing()

end

Window.Close()