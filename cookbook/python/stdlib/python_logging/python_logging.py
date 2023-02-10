import logging

log_format = '[%(asctime)s][%(name)s][%(levelname)s] %(message)s'

# Root Logger
def root_logger():

    logging.basicConfig(
        format=log_format, 
        datefmt="%Y-%m-%dT%H:%M:%S%z", # ISO format
        level=logging.DEBUG, 
        
        # filename='log', 
        # encoding='utf-8', 
        # filemode='w'
    )


    loglevel = 'DEBUG'
    print(getattr(logging, loglevel.upper()))

    logging.debug('debug')
    logging.info('info')
    logging.warning('warning')
    logging.error('error')
    logging.critical('critical')

# Custom Logger
def custom_logger():

    # https://docs.python.org/3/howto/logging-cookbook.html

    # name = __name__
    name = 'logger_00'
    logger = logging.getLogger(name)

    logger.setLevel(logging.DEBUG)
    # logger.setFormatter('[%(asctime)s][%(levelname)s] %(message)s')

    # create file handler
    fh = logging.FileHandler(filename='log', 
                             encoding='utf-8', 
                             mode='w')
    fh.setLevel(logging.DEBUG) # The logger's level filters every message before it can reach its handlers

    # create console handler
    ch = logging.StreamHandler()
    ch.setLevel(logging.DEBUG)

    # create formatter and add it to the handlers
    formatter = logging.Formatter(log_format)
    fh.setFormatter(formatter)
    ch.setFormatter(formatter)

    # add the handlers to the logger
    logger.addHandler(fh)
    logger.addHandler(ch)

    logger.debug('debug')
    logger.info('info')
    logger.warning('warning')
    logger.error('error')
    logger.critical('critical')


# LoggerAdapter()
def logger_adapter():

    # https://stackoverflow.com/questions/17558552/how-do-i-add-custom-field-to-python-log-format-string

    logger = logging.getLogger(__name__)
    syslog = logging.StreamHandler()
    formatter = logging.Formatter('[%(asctime)s][%(app_name)s] %(message)s')
    syslog.setFormatter(formatter)
    logger.setLevel(logging.INFO)
    logger.addHandler(syslog)

    # class extra_(object):
    #     def __init__(self):
    #         self.items = { 'app_name': 'App Name' }
    #     def __getitem__(self, key):
    #         return self.items[key]
    #     def __setitem__(self, key, value):
    #         self.items[key] = value
    # extra = extra_()
    # extra['app_name'] = 'App Name2'
    extra = { 'app_name': 'App Name' }
    logger = logging.LoggerAdapter(logger, extra)
    logger.info('info')

    # extra = { 'app_name': 'New Name' }
    # logger.info('info')


# AppFilter()
def app_filter():

    # https://stackoverflow.com/questions/17558552/how-do-i-add-custom-field-to-python-log-format-string

    class FilterClass(logging.Filter):
        def __init__(self):
            self.app_name = 'App Name'
            self.value    = -1
        def filter(self, record):
            record.app_name = self.app_name
            record.value = self.value
            return True

    logger = logging.getLogger(__name__)

    app_filter = FilterClass()
    logger.addFilter(app_filter)

    syslog = logging.StreamHandler()

    formatter = logging.Formatter('[%(asctime)s][%(app_name)s][%(value)s] %(message)s')
    syslog.setFormatter(formatter)

    logger.setLevel(logging.INFO)
    logger.addHandler(syslog)

    logger.info('info')

    app_filter.app_name = 'New Name'
    app_filter.value = 99
    logger.info('info')

if __name__ == '__main__': 

    print((logging.DEBUG, 
    logging.INFO, 
    logging.WARNING, 
    logging.ERROR, 
    logging.CRITICAL))

    print(logging.NOTSET)

    root_logger()
    custom_logger()
    logger_adapter()
    app_filter()
