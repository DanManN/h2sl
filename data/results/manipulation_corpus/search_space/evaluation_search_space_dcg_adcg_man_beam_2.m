% program to plot the search space statistics from the h2sl::search_space_corpus_analysis program

clear all;

dcg_ss_concrete_size = [302; 302; 302; 302; 302; 302; 302; 302; 302; 302; 342; 342; 342; 342; 342; 342; 342; 342; 342; 342; 342; 342; 342; 150; 150; 150; 150; 174; 174; 222; 174; 222; 174; 174; 222; 174; 174; 222; 222; 174; 222; 222; 222; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 222; 222; 174; 174; 174; 174; 174; 174; 222; 222; 222; 174; 174; 222; 222; 222; 222; 222; 222; 222; 222; 222; 174; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 174; 174; 222; 174; 174; 222; 174; 174; 222; 222; 222; 174; 222; 222; 222; 174; 222; 174; 174; 222; 222; 174; 222; 222; 222; 222; 222; 222; 222];
dcg_ss_abstract_avg_size = [38820; 38820; 38820; 38820; 38820; 38820; 38820; 38820; 38820; 38820; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 2744; 2744; 2744; 2744; 3284; 3284; 6668; 3284; 6668; 3284; 3284; 6668; 3284; 3284; 6668; 6668; 3284; 6668; 6668; 6668; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 6668; 6668; 3284; 3284; 3284; 3284; 3284; 3284; 6668; 6668; 6668; 3284; 3284; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 3284; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 3284; 3284; 6668; 3284; 3284; 6668; 3284; 3284; 6668; 6668; 6668; 3284; 6668; 6668; 6668; 3284; 6668; 3284; 3284; 6668; 6668; 3284; 6668; 6668; 6668; 6668; 6668; 6668; 6668];
dcg_ss_abstract_max_size = [38820; 38820; 38820; 38820; 38820; 38820; 38820; 38820; 38820; 38820; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 2744; 2744; 2744; 2744; 3284; 3284; 6668; 3284; 6668; 3284; 3284; 6668; 3284; 3284; 6668; 6668; 3284; 6668; 6668; 6668; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 6668; 6668; 3284; 3284; 3284; 3284; 3284; 3284; 6668; 6668; 6668; 3284; 3284; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 3284; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 3284; 3284; 6668; 3284; 3284; 6668; 3284; 3284; 6668; 6668; 6668; 3284; 6668; 6668; 6668; 3284; 6668; 3284; 3284; 6668; 6668; 3284; 6668; 6668; 6668; 6668; 6668; 6668; 6668];
baseline = dcg_ss_concrete_size + dcg_ss_abstract_avg_size;


adcg_ss_concrete_size = [302; 302; 302; 302; 302; 302; 302; 302; 302; 302; 342; 342; 342; 342; 342; 342; 342; 342; 342; 342; 342; 342; 342; 150; 150; 150; 150; 174; 174; 222; 174; 222; 174; 174; 222; 174; 174; 222; 222; 174; 222; 222; 222; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 222; 222; 174; 174; 174; 174; 174; 174; 222; 222; 222; 174; 174; 222; 222; 222; 222; 222; 222; 222; 222; 222; 174; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 174; 174; 222; 174; 174; 222; 174; 174; 222; 222; 222; 174; 222; 222; 222; 174; 222; 174; 174; 222; 222; 174; 222; 222; 222; 222; 222; 222; 222];
adcg_ss_abstract_avg_size = [254.5; 290.7; 888; 204; 508.1; 362.7; 182.1; 380.8; 888; 507.6; 1907; 629.7; 511.8; 3063; 86.81; 1.484; 767.4; 1150; 1788; 1533; 1533; 410; 410; 1.542; 1.542; 1.542; 1.5; 4.654; 4.654; 1.875; 1.833; 13.5; 3.179; 4.75; 25.38; 6.833; 4.067; 13.47; 13.63; 7.808; 25.9; 31.32; 25.85; 6.833; 4.083; 4.083; 6.6; 4.865; 4.125; 4.846; 6.833; 4.092; 6.833; 4.092; 4.654; 4.538; 4.635; 4.142; 4.158; 5.038; 13.57; 13.53; 4.4; 4.067; 4.615; 6.6; 4.654; 4.615; 13.5; 13.5; 13.5; 7.885; 4.175; 2.778; 13.63; 2.778; 1.633; 13.63; 2.778; 13.63; 1.633; 13.63; 3.179; 2.889; 2.778; 13.63; 2.778; 13.63; 1.567; 2.857; 1.633; 25.53; 13.63; 13.5; 13.5; 1.633; 13.63; 2.778; 1.633; 2.778; 2.778; 13.63; 1.633; 13.5; 13.63; 2.611; 3.25; 2.611; 4.083; 4.1; 2.611; 2.611; 2.611; 2.611; 2.611; 2.611; 2.778; 2.611; 2.611; 2.611; 2.611; 25.43; 1.5; 4.125; 13.53; 2.333; 1.25; 2.571; 1.808; 1.375; 3.25; 15.54; 1.25; 29.15];
adcg_ss_abstract_max_size = [306.1; 437.3; 1268; 306; 764.5; 435.7; 435.3; 760.8; 1268; 762; 1908; 630.1; 512.1; 3064; 342.2; 1.938; 767.6; 1278; 1788; 1788; 1789; 818.5; 818.5; 1.833; 1.833; 1.833; 1.889; 7.846; 7.923; 2.167; 2.25; 25.73; 4.286; 8; 25.73; 7.4; 6.933; 25.73; 25.87; 8.462; 26.2; 37.8; 26.2; 7.467; 7; 7; 7; 8.231; 7; 8.154; 7.4; 7; 7.4; 7; 7.923; 7.923; 7.846; 7; 7; 8.538; 25.73; 25.73; 7.467; 7; 7.923; 7; 7.923; 7.923; 25.8; 25.73; 25.73; 8.385; 7; 3.444; 25.87; 3.444; 1.933; 25.87; 3.444; 25.87; 1.933; 25.87; 4.286; 3.444; 3.444; 25.87; 3.444; 25.93; 1.933; 4.286; 1.933; 25.87; 25.87; 25.73; 25.73; 1.933; 25.87; 3.444; 1.933; 3.444; 3.444; 25.87; 1.933; 25.73; 25.87; 3.222; 4.286; 3.222; 6.933; 6.933; 3.222; 3.222; 3.222; 3.222; 3.222; 3.222; 3.444; 3.222; 3.222; 3.222; 3.222; 25.73; 1.933; 7; 25.73; 3.222; 2; 3.143; 2.077; 2.25; 4.286; 29.54; 2; 29.54];
adcg_adaptive_avg = adcg_ss_concrete_size + adcg_ss_abstract_avg_size;
adcg_adaptive_max = adcg_ss_concrete_size + adcg_ss_abstract_max_size;


figure(1);
hold on;
box on;
grid on;
scatter(baseline,baseline,200);
scatter(baseline,adcg_adaptive_avg,200,'+');
scatter(baseline,adcg_adaptive_max,200,'s');
legend('DCG','ADCG avg', 'ADCG max','Location','NorthWest');
title('Search space comparison');
xlhand = get(gca,'xlabel');
set(xlhand,'string','Total search space size','fontsize',15);
ylhand = get(gca,'ylabel');
set(ylhand,'string','Instantiated search space size','fontsize',15);
set(gcf, 'PaperPosition', [0 0 6 6]);
set(gcf, 'PaperSize', [6 6]);
set(gca, 'yscale', 'log');
set(gca, 'xscale', 'log');

saveas(gcf, 'search_space_comparison_dcg_adcg_man_beam_width_2', 'epsc');

saveas(gcf, 'search_space_comparison_dcg_adcg_man_beam_width_2', 'pdf');

