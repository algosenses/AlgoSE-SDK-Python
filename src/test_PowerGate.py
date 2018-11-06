from PowerGate import StrategyWrapper
from PowerGate import StrategyConfig

class MyStrategy(StrategyWrapper):
	def onStart(self):
		print 'MyStrategy::onStart()'

	def onBar(self, bar):
		print bar.getLastPrice()

	def onStop(self):
		print 'MyStrategy::onStop()'


if __name__ == '__main__':
	config = StrategyConfig()
	config.setName('Demo')
	config.subscribe("rb1705");

	strategy = MyStrategy()

	strategy.run(config)

	raw_input()

	strategy.stop()