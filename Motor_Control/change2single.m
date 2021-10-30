% 脚本作用: 转换选定子系统中所有模块的变量类型为single.
% 使用方法: 打开需要转换的模型，打开待转换子系统界面，运行此脚本.

% 遍历找出子系统所有模块句柄.
load_system(gcs);
sys = get_param(gcs, 'Handle');
submodels = find_system(sys);

% 计算待转换模块的数量.
size_submodels = size(submodels);

% 尝试将所有模块变量类型转换为single, 遇到不需要转换的模块自动跳过.
for i=1:size_submodels(1)
    try
        set_param(submodels(i),'OutDataTypeStr', 'single');
    catch
        
    end
end

clear i size_submodels submodels sys