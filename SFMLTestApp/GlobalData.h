#pragma once
/*
  ƒанный класс отвечает за хранение с ID ресурсов, загружаемых в программу
*/

namespace Textures {
    enum class ID {
        Hero,
    };
}

namespace Fonts {
    enum class ID
    {
        FPS,
    };
}

namespace Layers {
    enum class Layer {
        Background,
        Entities,
        LayersCount     // Ќе €вл€етс€ слоем, служит дл€ определени€ количества слоев в данном перечислении
    };
}