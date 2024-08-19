Window.Init("Demo App", 800, 600)
Window.SetTargetFPS(60)

local oceanblue <const> = Color(0, 105, 148, 255)
local white <const> = Color(255, 255, 255, 255)

while not Window.ShouldClose() do

    Window.BeginDrawing()
    Window.ClearBackground(oceanblue)

    -- draw mouse position
    local mouse_pos = Input.GetMousePosition()
    Graphics2D.DrawText("Mouse Position: " .. mouse_pos.x .. ", " .. mouse_pos.y, Vector2(10, 10), 20, white)

    -- draw mouse button state
    local left_mouse_down = Input.IsMouseButtonDown(MouseButton.Left)
    Graphics2D.DrawText("Left Mouse Down: " .. tostring(left_mouse_down), Vector2(10, 30), 20, white)

    -- is mouse on screen
    local mouse_on_screen = Window.IsCursorOnScreen()
    Graphics2D.DrawText("Mouse On Screen: " .. tostring(mouse_on_screen), Vector2(10, 50), 20, white)

    -- is gamepad available
    local gamepad_available = Input.IsGamepadAvailable(0)
    local name = Input.GetGamepadName(0)
    Graphics2D.DrawText("Gamepad Available: " .. tostring(gamepad_available) .. " (" .. name .. ")", Vector2(10, 70), 20, white)

    Window.EndDrawing()

end

Window.Close()