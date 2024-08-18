local modules = {
    "window",
    "graphics2d",
}

local function parse_lua_functions(file)
    local f = io.open(file, "r")
    local content = f:read("*all")
    f:close()

    local tag_start = "//%s*%-%-%s*@"
    local match_tag = tag_start .. "(%w+)"
    local match_function = tag_start .. "function%s*(%w+)"
    local match_desecription = tag_start .. "description%s*(.+)"
    local match_return = tag_start .. "return%s*(%w+)%s*(.+)"
    local match_param = tag_start .. "param%s*(%w+)%s*(%w+)%s*(.+)"

    local functions = {}
    local function_ptr
    for line in content:gmatch("[^\r\n]+") do
    
        -- if the comment starts with a luadoc tag
        if line:match(tag_start) then
            local tag = line:match(match_tag)
            if tag == "function" then
                function_ptr = #functions + 1
                functions[function_ptr] = {
                    name = line:match(match_function),
                    args = {}
                }
            elseif tag == "description" then
                if function_ptr then
                    functions[function_ptr].desc = line:match(match_desecription)
                end
            elseif tag == "return" then
                local type, desc = line:match(match_return)
                if function_ptr then
                    functions[function_ptr].rtn = {
                        type = type,
                        desc = desc
                    }
                end
            elseif tag == "param" then
                local arg, type, desc = line:match(match_param)
                if function_ptr then
                    table.insert(functions[function_ptr].args, {
                        name = arg,
                        type = type,
                        desc = desc
                    })
                end
            end
        end


    end

    return functions
end

-- open yaml
local yaml = io.open("docs/doc.yaml", "w")
yaml:write("modules:\n")

-- parse each module
for _, module in ipairs(modules) do
    local functions = parse_lua_functions("src/modules/" .. module .. ".cpp")

    -- write yaml
    yaml:write("  - name: " .. module .. "\n")
    yaml:write("    functions:\n")
    for _, func in ipairs(functions) do
        yaml:write("      - name: " .. func.name .. "\n")
        yaml:write("        description: " .. (func.desc) .. "\n")
        yaml:write("        return:\n")
        yaml:write("          type: " .. func.rtn.type .. "\n")
        yaml:write("          description: " .. func.rtn.desc .. "\n")
        yaml:write("        params:\n")
        for _, arg in ipairs(func.args) do
            yaml:write("          - name: " .. arg.name .. "\n")
            yaml:write("            type: " .. arg.type .. "\n")
            yaml:write("            description: " .. arg.desc .. "\n")
        end
    end
end

-- close yaml
yaml:close()