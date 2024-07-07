import matplotlib.pyplot as plt
import json
import os
with open('./prepdata/data_file.json', 'r') as json_file:
    data = json.load(json_file)
os.chdir("./postprocdata")
graph_type = ('o-', '^-', 's-')

line_width = 0.2
marker_size = 0.5
box_plot_width = 0.5
# Линейный график
for data_type, data_type_value in data.items():
    plt.clf()
    if data_type == "data1":
        name_type = "in_measure_nanosec"
    elif data_type == "data3":
         name_type = "in_measure_ticks"
    else:
        name_type = "out_measure_nanosec"
    plt.title(f"{name_type}_linear")
    plt.grid()
    i = 0
    for access_type, access_type_value in data_type_value.items():
        if access_type == "idx":
            access_name = "indexation"
        elif access_type == "ptr":
            access_name = "pointer_access"
        else:
            access_name = "formal_indexation"
        if data_type == "data1":
            plt.xlabel("Размерность, кол-во элементов")
            plt.ylabel("Время, наносекунды")
        elif data_type == "data3":
            plt.xlabel("Размерность, кол-во элементов")
            plt.ylabel("Тики")
        x = []
        y = []
        for key in sorted([int(x) for x in access_type_value.keys()]):
            x.append(key)
            y.append(access_type_value[str(key)][0])
        plt.plot(x, y, graph_type[i], linewidth=line_width, markersize=marker_size, label=f'{access_name}')
        i += 1
    plt.xticks([i for i in range(0, max(x)+1000, 1000)], rotation=45)
    plt.legend()
    plt.savefig(f"{name_type}_linear.svg", bbox_inches='tight')

# Линейный график с ошибкой
for data_type, data_type_value in data.items():
    plt.clf()
    if data_type == "data1":
        name_type = "in_measure_nanosec"
    elif data_type == "data3":
         name_type = "in_measure_ticks"
    else:
        name_type = "out_measure_nanosec"

    plt.grid()
    for access_type, access_type_value in data_type_value.items():
        plt.clf()
        if access_type == "idx":
            access_name = "indexation"
        elif access_type == "ptr":
            access_name = "pointer_access"
        else:
            access_name = "formal_indexation"
        if data_type == "data1":
            plt.xlabel("Размерность, кол-во элементов")
            plt.ylabel("Время, наносекунды")
        elif data_type == "data3":
            plt.xlabel("Размерность, кол-во элементов")
            plt.ylabel("Тики")


        x = []
        y_av = []
        y_min = []
        y_max = []
        y_av_err = []
        for key in sorted([int(x) for x in access_type_value.keys()]):
            x.append(key)
            y_av.append(access_type_value[str(key)][0])
            y_min.append(access_type_value[str(key)][5])
            y_max.append(access_type_value[str(key)][4])
            y_av_err.append(access_type_value[str(key)][3])
        plt.grid()
        plt.plot(x, y_av, graph_type[0], linewidth=line_width, markersize=marker_size, label=f'{access_name} average')
        plt.plot(x, y_min, graph_type[1], linewidth=line_width, markersize=marker_size, label=f'{access_name} min')
        plt.plot(x, y_max, graph_type[2], linewidth=line_width, markersize=marker_size, label=f'{access_name} max')
        plt.title(f"{name_type}_{access_name}_err")
        for i in range(len(x)):
            plt.errorbar(x[i], y_av[i], y_av_err[i], color='red')
        plt.legend()
        plt.savefig(f"err_{name_type}_{access_name}.svg", bbox_inches='tight')
    plt.xticks([i for i in range(0, max(x)+1000, 1000)], rotation=45)
# График с усами
for data_type, data_type_value in data.items():
    plt.clf()

    if data_type == "data1":
        name_type = "in_measure_nanosec"
    elif data_type == "data3":
         name_type = "in_measure_ticks"
    else:
        name_type = "out_measure_nanosec"
    if data_type == "data1":
        plt.xlabel("Размерность, кол-во элементов")
        plt.ylabel("Время, наносекунды")
    elif data_type == "data3":
        plt.xlabel("Размерность, кол-во элементов")
        plt.ylabel("Тики")
    access_name = "Indexation"
    plt.title(f"moustache_{name_type}_{access_name}")
    access_type_value = data_type_value['idx']
    x = []
    data = []
    medians = []
    y_av = []
    for key in sorted([int(x) for x in access_type_value.keys()]):
        x.append(key)
        data.append(access_type_value[str(key)][9])
        y_av.append(access_type_value[str(key)][0])

    plt.grid()
    plt.xticks(rotation=45)
    plt.boxplot(data, labels=x, showfliers=False, widths=box_plot_width)

    plt.savefig(f"moustache_{name_type}_{access_name}.svg", bbox_inches='tight')

