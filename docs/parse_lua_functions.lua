local modules = {
    "window",
    "graphics2d",
    "input",
}

local function parse_lua_functions(filename)
    local file = io.open(filename, "r")

    if not file then
        print("Could not open file: " .. filename)
        return
    end

    local luadoc_match = "//%s*%-%-%s*@(%w+)%s*(.*)"
    local return_match = "(%w+)%s*(.*)"
    local param_match = "(%w+)%s+(%w+)%s*(.*)"

    local functions = {}
    local function_ptr = 0;
    for line in file:lines() do
    
        local tag, body = line:match(luadoc_match)

        if tag then

            if tag == "function" then
                function_ptr = function_ptr + 1
                functions[function_ptr] = {
                    name = body,
                    description = "",
                    usage = {},
                    args = {},
                    rtn = {},
                }
            elseif tag == "description" then
                functions[function_ptr].description = body
            elseif tag == "usage" then
                table.insert(functions[function_ptr].usage, body)
            elseif tag == "param" then
                local name, type, desc = body:match(param_match)
                table.insert(functions[function_ptr].args, {
                    name = name,
                    type = type,
                    description = desc,
                })
            elseif tag == "return" then
                local type, desc = body:match(return_match)
                if type ~= "void" then
                    functions[function_ptr].rtn = {
                        type = type,
                        description = desc,
                    }
                end
            end
            
        end


    end

    file:close()

    return functions
end

-- open yaml
local yaml = io.open("docs/doc.yaml", "w")

if not yaml then
    print("Could not open file: docs/doc.yaml")
    return
end

yaml:write("modules:\n")

-- parse each module
for _, module in ipairs(modules) do

    print("Documenting module: " .. module)

    local functions = parse_lua_functions("src/modules/" .. module .. ".cpp")

    -- capitalise first letter
    module = module:gsub("^%l", string.upper)

    -- write yaml
    yaml:write("  - name: " .. module .. "\n")
    yaml:write("    functions:\n")
    for _, func in ipairs(functions) do
        yaml:write("      - name: " .. func.name .. "\n")
        yaml:write("        description: " .. (func.description) .. "\n")
        if #func.usage > 0 then
            yaml:write("        usage:\n")
            for _, usage in ipairs(func.usage) do
                yaml:write("          - " .. usage .. "\n")
            end
        end
        if #func.rtn > 0 then
            yaml:write("        return:\n")
            yaml:write("          type: " .. func.rtn.type .. "\n")
            yaml:write("          description: " .. (func.rtn.description or "no description") .. "\n")
        end
        yaml:write("        params:\n")
        for _, arg in ipairs(func.args) do
            yaml:write("          - name: " .. arg.name .. "\n")
            yaml:write("            type: " .. arg.type .. "\n")
            yaml:write("            description: " .. (arg.description or "no description") .. "\n")
        end
    end
end

-- close yaml
yaml:close()