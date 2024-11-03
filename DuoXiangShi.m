function y=DduoXiangShi(x)
y=+exp(sin(x+cos(x.*x)));
end
fun = @(x) log( log( exp(x.^2)./log(x).^2  ));
hold on
fplot(@(x) DduoXiangShi(x) )
J_fun = @(y) integral(fun,y.^y,y);
fplot(@(x) fun(x) )